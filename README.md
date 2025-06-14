## General CUDA raytracer for my learning purposes

This code is taken from [Accelerated Ray Tracing in One Weekend in CUDA](https://developer.nvidia.com/blog/accelerated-ray-tracing-cuda) by [Roger Allen](https://developer.nvidia.com/blog/author/rallen/) ([github repository](https://github.com/RayTracing/InOneWeekend)).

It is meant to teach me how to utilize the GPU to perform raytracing, a rather "emberassly parallelizeable" problem.

Instead of following the tutorial step-by-step, My plan is to generalize and upgrade the code with extra features.

For example, switching to either using 4-vectors and 4×4 matrices for transformations, or even the simple geometric algebra over $\mathbb{R}^{3}$, namely $\text{Cl}_{\mathbb{R}}\left(3,0,0\right)$.
