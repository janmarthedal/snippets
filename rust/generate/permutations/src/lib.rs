pub struct Permutations<T> {
    vec: Vec<T>,
    subsize: usize,
    first: bool,
}

impl<T: Clone + Ord> Iterator for Permutations<T> {
    type Item = Vec<T>;

    fn next(&mut self) -> Option<Vec<T>> {
        let n = self.vec.len();
        let r = self.subsize;
        if n == 0 || r == 0 || r > n {
            return None;
        }
        if self.first {
            self.vec.sort();
            self.first = false;
        } else if self.vec[r - 1] < self.vec[n - 1] {
            let mut j = r;
            while self.vec[j] <= self.vec[r - 1] {
                j += 1;
            }
            self.vec.swap(r - 1, j);
        } else {
            self.vec[r..n].reverse();
            let mut j = r - 1;
            while j > 0 && self.vec[j - 1] >= self.vec[j] {
                j -= 1;
            }
            if j == 0 {
                return None;
            }
            let mut l = n - 1;
            while self.vec[j - 1] >= self.vec[l] {
                l -= 1;
            }
            self.vec.swap(j - 1, l);
            self.vec[j..n].reverse();
        }
        Some(self.vec[0..r].to_vec())
    }

    fn size_hint(&self) -> (usize, Option<usize>) {
        let n = self.vec.len();
        let r = self.subsize;
        if n == 0 || r == 0 || r > n {
            (0, Some(0))
        } else {
            (1, Some(((n - r + 1)..=n).product()))
        }
    }
}

pub fn permutations<T: Clone + Ord>(s: &[T], subsize: usize) -> Permutations<T> {
    Permutations {
        vec: s.to_vec(),
        subsize,
        first: true,
    }
}
