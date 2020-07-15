fn main() {
    for p in generate_permutations::permutations(&[1, 2, 2, 3], 4) {
        println!("{:?}", p);
    }
}