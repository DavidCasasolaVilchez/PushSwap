# `push_swap` Project

## Summary

The program receives a list of integers, stores it in stack `a`, and sorts its elements in ascending order using only Push_swap operations. Stack `b` starts empty, and the smallest number must be at the top of `a` when the program finishes.

The project requires four sorting strategies written in C. The strategy is selected through a command-line option; when no option is provided, the adaptive strategy is used.

## Rules and Operations

There are two stacks:

- `a`: contains the input values.
- `b`: starts empty.

| Operation | Effect |
| --- | --- |
| `sa` | Swaps the first two elements of stack `a`. Does nothing if there are one or no elements. |
| `sb` | Swaps the first two elements of stack `b`. Does nothing if there are one or no elements. |
| `ss` | Executes `sa` and `sb` simultaneously. |
| `pa` | Moves the first element of stack `b` to the top of stack `a`. Does nothing if `b` is empty. |
| `pb` | Moves the first element of stack `a` to the top of stack `b`. Does nothing if `a` is empty. |
| `ra` | Moves all elements of stack `a` up by one position, moving the first element to the bottom. |
| `rb` | Moves all elements of stack `b` up by one position, moving the first element to the bottom. |
| `rr` | Executes `ra` and `rb` simultaneously. |
| `rra` | Moves all elements of stack `a` down by one position, moving the last element to the top. |
| `rrb` | Moves all elements of stack `b` down by one position, moving the last element to the top. |
| `rrr` | Executes `rra` and `rrb` simultaneously. |

Operations on stacks containing fewer than two elements have no effect.

## Disorder Index

The disorder index is calculated from the original stack `a`, before any moves are made:

$$
	ext{disorder} = \frac{\text{inverted pairs}}{\text{total pairs}}
$$

A pair is inverted when a larger number appears before a smaller one. Therefore, `0` represents a sorted stack and `1` represents the maximum possible disorder. If `n < 2`, the index is considered to be `0` to avoid division by zero.

## Required Strategies

Complexity must be analyzed according to the number of Push_swap operations generated, not according to a traditional array-based implementation.

### Simple Strategy: `O(n²)`

Implement a basic algorithm adapted to two stacks, such as insertion sort, selection sort, bubble sort, or repeated extraction of the minimum or maximum.

### Intermediate Strategy: `O(n√n)`

Implement a strategy based on blocks, chunks, or ranges. One recommended option is to divide the indexed values into approximately `√n` chunks.

### Complex Strategy: `O(n log n)`

Implement a strategy such as radix sort adapted to Push_swap, merge sort using two stacks, or an equivalent partitioning method that meets the declared bound.

### Adaptive Strategy

The strategy must select its method according to the disorder index:

| Disorder index | Method | Target complexity |
| --- | --- | --- |
| `disorder < 0.2` | Method for nearly sorted inputs | `O(n)` |
| `0.2 ≤ disorder < 0.5` | Chunks or ranges | `O(n√n)` |
| `disorder ≥ 0.5` | Complex method, such as radix sort | `O(n log n)` |

The repository must justify the thresholds and document the techniques, as well as the time and space bounds, within the Push_swap operation model.

## Program Interface

The executable must be named `push_swap`. The first numeric argument represents the initial top of stack `a`.

| Option | Behavior |
| --- | --- |
| `--simple` | Forces the `O(n²)` strategy. |
| `--medium` | Forces the `O(n√n)` strategy. |
| `--complex` | Forces the `O(n log n)` strategy. |
| `--adaptive` | Uses the adaptive strategy and is the default option. |
| `--bench` | Displays statistics on `stderr` after sorting. |

Selectors must work with any input size and disorder index. Normal output must contain only the generated operations, one per line. With no arguments, the program must produce no output and exit successfully.

## Validation and Errors

Reject values that are not integers, values outside the `int` range, duplicate numbers, and unknown options. On error, write exactly `Error\n` to `stderr`.

## Benchmark Mode

With `--bench`, write the following exclusively to `stderr`:

- Initial disorder index as a percentage with two decimal places.
- Strategy name and complexity class.
- Total number of operations.
- Counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

`stdout` must still contain only the operation sequence.

## Technical Constraints

- Language: C.
- Minimum deliverables: `Makefile`, `.h` files, and `.c` files.
- The `Makefile` must include `NAME`, `all`, `clean`, `fclean`, and `re`, without unnecessary relinking.
- Global variables are not allowed.
- Authorized functions: `read`, `write`, `malloc`, `free`, `exit`, and `ft_printf` or an equivalent custom function.
- `libft` may be used.

## Project Starting Points

### 1. Represent the Stacks

Choose a linked list with pointers to the first and last node, or a dynamic array with its sizes. The representation must support `push`, `swap`, and rotations without duplicating logic.

### 2. Separate Responsibilities

Organize the project into modules:

- **Parsing and validation:** arguments, safe `int` conversion, duplicates, and options.
- **Data structures:** stack creation, cleanup, and access.
- **Operations:** the eleven operations and instruction output.
- **Utilities:** normalized indexes, positions, and sorted-state checks.
- **Strategies:** `simple`, `medium`, `complex`, and `adaptive`.
- **Benchmark:** operation counter, initial disorder, and `stderr` output.

### 3. Normalize the Values

Create a sorted copy and assign each value its relative position (`0` to `n - 1`). Coordinate compression simplifies handling negative numbers, large values, and radix sort.

### 4. Implement Primitive Operations First

Test `sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, and their combined variants individually. Each operation must update the stacks and its benchmark counter.

### 5. Use a Common API

All strategies should call the same operation API instead of manipulating the internal stack representation directly. This makes testing and counting easier.

### 6. Recommended Implementation Order

1. Parsing, validation, and memory management.
2. Stacks `a` and `b`.
3. Primitive operations and final-state checks.
4. Cases from zero to five elements.
5. Simple strategy.
6. Coordinate compression and complex strategy.
7. Chunk or range strategy.
8. Disorder calculation and adaptive strategy.
9. Benchmark and complexity documentation.

### 7. Minimum Test Plan

Test every operation and verify that each strategy sorts already sorted, reversed, and random inputs; handles positive values, negative values, and `int` limits; rejects duplicates and invalid input; leaves `b` empty; writes only operations to `stdout`; and produces correct statistics with `--bench`.

## Expected Result

The binary must sort every valid input, use the requested strategy, respect the exact Push_swap output format, and justify the complexity of every strategy according to the generated operations.
