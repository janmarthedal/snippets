use criterion::{criterion_group, criterion_main, Criterion};

fn criterion_benchmark(c: &mut Criterion) {
    c.bench_function("one", |b| {
        let digits = &[0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
        b.iter(|| generate_permutations::sub_permutations(digits, 8))
    });
}

criterion_group!(benches, criterion_benchmark);
criterion_main!(benches);
