#[derive(Debug, PartialEq)]
pub struct Set<T> {
    elems: Vec<T>,
}

impl<T: Copy + Ord> Set<T> {
    pub fn new(input: &[T]) -> Self {
        let mut elems = input.to_vec();
        elems.sort();
        elems.dedup();
        Self { elems }
    }

    pub fn contains(&self, element: &T) -> bool {
        self.elems.binary_search(element).is_ok()
    }

    pub fn add(&mut self, element: T) {
        if let Err(index) = self.elems.binary_search(&element) {
            self.elems.insert(index, element);
        }
    }

    pub fn is_subset(&self, other: &Self) -> bool {
        self.elems.iter().all(|v| other.contains(v))
    }

    pub fn is_empty(&self) -> bool {
        self.elems.is_empty()
    }

    pub fn is_disjoint(&self, other: &Self) -> bool {
        self.elems.iter().all(|v| !other.contains(v))
    }

    pub fn intersection(&self, other: &Self) -> Self {
        let elems: Vec<T> = self
            .elems
            .iter()
            .filter(|v| other.contains(v))
            .copied()
            .collect();
        Self { elems }
    }

    pub fn difference(&self, other: &Self) -> Self {
        let elems: Vec<T> = self
            .elems
            .iter()
            .filter(|v| !other.contains(v))
            .copied()
            .collect();
        Self { elems }
    }

    pub fn union(&self, other: &Self) -> Self {
        let mut elems: Vec<T> = self
            .elems
            .iter()
            .chain(other.elems.iter())
            .copied()
            .collect();
        elems.sort();
        elems.dedup();
        Self { elems }
    }
}
