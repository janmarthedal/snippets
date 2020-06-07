#[cfg(test)]
mod tests {
    #[test]
    fn empty() {
        let v: &[u32] = &[];
        assert_eq!(generate_permutations::sub_permutations(v, 0).next(), None);
        assert_eq!(generate_permutations::sub_permutations(v, 1).next(), None);
    }

    #[test]
    fn single() {
        let v = &[1];
        assert_eq!(generate_permutations::sub_permutations(v, 0).next(), None);
        assert_eq!(
            generate_permutations::sub_permutations(v, 1).collect::<Vec<Vec<u32>>>(),
            &[[1]]
        );
        assert_eq!(generate_permutations::sub_permutations(v, 2).next(), None);
    }

    #[test]
    fn numbers() {
        let v = &[1, 2, 3];
        assert_eq!(generate_permutations::sub_permutations(v, 0).next(), None);
        assert_eq!(
            generate_permutations::sub_permutations(v, 1).collect::<Vec<Vec<u32>>>(),
            &[[1], [2], [3]]
        );
        assert_eq!(
            generate_permutations::sub_permutations(v, 2).collect::<Vec<Vec<u32>>>(),
            &[[1, 2], [1, 3], [2, 1], [2, 3], [3, 1], [3, 2]]
        );
        assert_eq!(
            generate_permutations::sub_permutations(v, 3).collect::<Vec<Vec<u32>>>(),
            &[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]
        );
        assert_eq!(generate_permutations::sub_permutations(v, 4).next(), None);
    }

    #[test]
    fn chars() {
        let v = &['A', 'B', 'C'];
        assert_eq!(
            generate_permutations::sub_permutations(v, 2).collect::<Vec<Vec<char>>>(),
            &[['A', 'B'], ['A', 'C'], ['B', 'A'], ['B', 'C'], ['C', 'A'], ['C', 'B']]
        );
    }

}
