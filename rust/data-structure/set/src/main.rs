use set::Set;

fn main() {
    let a = Set::new(&[1, 2, 3]);
    let b = Set::new(&[2, 4]);
    let c = a.intersection(&b);
    assert!(c.contains(&2));
}
