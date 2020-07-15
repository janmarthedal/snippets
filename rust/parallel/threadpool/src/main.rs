use std::thread;
use std::time::Duration;

fn main() {
    let pool = threadpool::ThreadPool::new(4);

    for n in 0..6 {
        pool.execute(move || {
            thread::sleep(Duration::from_millis(200));
            println!("Task {}", n);
        })
    }

    thread::sleep(Duration::from_millis(1000));
}
