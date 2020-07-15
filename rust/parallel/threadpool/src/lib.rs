use std::sync::mpsc;
use std::sync::Arc;
use std::sync::Mutex;
use std::thread;

// ThreadPool inspired by https://doc.rust-lang.org/book/ch20-02-multithreaded.html

type Job = Box<dyn FnOnce() + Send + 'static>;

pub struct ThreadPool {
    sender: mpsc::Sender<Job>,
}

impl ThreadPool {
    pub fn new(size: usize) -> ThreadPool {
        let (sender, receiver) = mpsc::channel::<Job>();
        let receiver = Arc::new(Mutex::new(receiver));

        for _ in 0..size {
            let receiver = Arc::clone(&receiver);
            thread::spawn(move || loop {
                let job_item = receiver.lock().unwrap().recv();
                match job_item {
                    Ok(job) => job(),
                    _ => break,
                }
            });
        }

        ThreadPool { sender }
    }

    pub fn execute<F: FnOnce() + Send + 'static>(&self, f: F) {
        let job = Box::new(f);
        self.sender.send(job).unwrap();
    }
}
