## Algorithms Analysis

We will determine the efficiency of algorithms based on **space and time complexity**.  
This is important to determine how much resources will be required to sustain the program.

---

#### Questions to Answer

1. How to estimate the time required?
2. How to reduce the running time to fractions?
3. Why the hell didn’t I think of this before?

---

#### Mathematical Background

The analysis required to estimate the resources used by an algorithm is generally a theoretical issue.

- **Def.** T(N) = O(f(N)) if there are positive constants `c` and `n0` such that T(N) ≤ c f(N) when N ≥ n0.
- **Def.** T(N) = Ω(g(N)) if there are positive constants `c` and `n0` such that T(N) ≥ c g(N) when N ≥ n0.
- **Def.** T(N) = Θ(h(N)) if T(N) = O(h(N)) and T(N) = Ω(h(N)).
- **Def.** T(N) = o(p(N)) if T(N) = O(p(N)) and T(N) ≠ Θ(p(N)).

The first definition says that eventually there is some point n0 past which f(N) is always at least as large as T(N).  
So, if constant factors are ignored, f(N) is at least as big as T(N).

**Example:**

```
1000N is larger than N² for small values of N.
In this case:
T(N) = 1000N, F(N) = N², n0 = 1000, c = 1
Thus: 1000N = O(N²) (order N-squared)
```

This is called **Big-O notation**

---

## Important Things to Know

#### Rule 1

If T1(N) = O(f(N)) and T2(N) = O(g(N)) then:

- a) T1(N) + T2(N) = max(O(f(N)), O(g(N)))
- b) T1(N) _ T2(N) = O(f(N) _ g(N))

#### Rule 2

If T(N) is a polynomial of degree k, then T(N) = Θ(N^k). Typical growth rates.

#### Rule 3

log^k(N) = O(N) for any constant k.  
This tells us that logarithms grow very slow.

We can always determine the relative growth rates of two functions f(N) and g(N) by comparing:

```
lim (f(N)/g(N)) as N → ∞
```

(using L'Hôpital’s rule if necessary).  
The limit has four possible values:

- Limit = 0 → f(N) = o(g(N))
- Limit = c → f(N) = Θ(g(N))
- Limit = ∞ → f(N) = ω(g(N))

Here g(N) is the comparison function (upper bound or lower bound).

---

#### Typical Growth Rates

| Function | Name        |
| -------- | ----------- |
| C        | Constant    |
| log N    | Logarithmic |
| log² N   | Log-squared |
| N        | Linear      |
| N log N  |             |
| N²       | Quadratic   |
| N³       | Cubic       |

---

## Time Analysis

Focus on the **average** and **worst case**, T_avg(N) and T_worst(N), that are used by an algorithm on input size N.  
Clearly: T_avg(N) ≤ T_worst(N).

#### Running time calculation

Running time is based on constants since there are no particular units of time.  
Basically, we are computing **Big-O running time**.

Example: Calculate

```
Σ (i=1 to N) i^3
```

```cpp
int partialSum(int N) {
    int sum = 0;                    // line 1
    for (int i = 1; i < N; i++) {   // line 2
        sum += i * i;               // line 3
    }
    return sum;                     // line 4
}
```

#### Analysis

- Line 1: one initialization → 1 time.
- Line 2: has initialization, test case (N times), and increment (N times).
- Line 3: uses four operation symbols, covered each N times → 4N.
- Line 4: one operation.

**Total = 6N + 4**

∴ The function is **O(N)**.
