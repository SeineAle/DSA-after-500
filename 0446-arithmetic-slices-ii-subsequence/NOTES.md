Starting from this point, we can easily figure out that one state representation that may work:

f[i][d] denotes the number of arithmetic subsequences that ends with A[i] and its common difference is d.

Let's try to find the state transitions based on the representation above. Assume we want to append a new element A[i] to existing arithmetic subsequences to form new subsequences. We can append A[i] to an existing arithmetic subsequence, only if the difference between the sequence's last element and A[i] is equal to the sequence's common difference.

Thus, we can define the state transitions for the element A[i] intuitively :

for all j < i, f[i][A[i] - A[j]] += f[j][A[i] - A[j]].

This demonstrates the appending process above to form new arithmetic subsequences.

But here comes the problem. Initially all f[i][d] are set to be 0, but how can we form a new arithmetic subsequence if there are no existing subsequences before?

In the original definition of arithmetic subsequences, the length of the subsequence must be at least 3. This makes it hard to form new subsequences if only two indices i and j are given. How about taking the subsequences of length 2 into account?

We can define weak arithmetic subsequences as follows:

Weak arithmetic subsequences are subsequences that consist of at least two elements and if the difference between any two consecutive elements is the same.

There are two properties of weak arithmetic subsequences that are very useful:

For any pair i, j (i != j), A[i] and A[j] can always form a weak arithmetic subsequence.

If we can append a new element to a weak arithmetic subsequence and keep it arithmetic, then the new subsequence must be an arithmetic subsequence.

The second property is quite trival, because the only difference between arithmetic subsequences and weak arithmetic subsequences is their length.

Thus we can change the state representations accordingly:

f[i][d] denotes the number of weak arithmetic subsequences that ends with A[i] and its common difference is d.

Now the state transitions are quite straightforward:

for all j < i, f[i][A[i] - A[j]] += (f[j][A[i] - A[j]] + 1).

The 1 appears here because of the property one, we can form a new weak arithmetic subsequence for the pair (i, j).

Now the number of all weak arithmetic subsequences is the sum of all f[i][d]. But how can we get the number of arithmetic subsequences that are not weak?

There are two ways:

First, we can count the number of pure weak arithmetic subsequences directly. The pure weak arithmetic subsequences are the arithmetic subsequences of length 2, so the number of pure weak arithmetic subsequences should be equal to the number of pairs (i, j), which is (n2)=n∗(n−1)2.\binom{n}{2} = \frac{n * (n - 1)}{2}.( 
2
n
​
 )= 
2
n∗(n−1)
​
 .

Second, for the summation f[i][A[i] - A[j]] += (f[j][A[i] - A[j]] + 1), f[j][A[i] - A[j]] is the number of existing weak arithmetic subsequences, while 1 is the new subsequence built with A[i] and A[j]. Based on property two, when we are appending new elements to existing weak arithmetic subsequences, we are forming arithmetic subsequences. So the first part, f[j][A[i] - A[j]] is the number of new formed arithmetic subsequences, and can be added to the answer.

We can use the following example to illustrate the process:

[1, 1, 2, 3, 4, 5]

We need to count the answer for the above sequence.

For the first element 1, there is no element in front of it, the answer remains 0.

For the second element 1, the element itself with the previous 1 can form a pure weak arithmetic subsequence with common difference 0 : [1, 1].

For the third element 2, it cannot be appended to the only weak arithmetic subsequence [1, 1], so the answer remains 0. Similar to the second element, it can form new weak arithmetic subsequences [1, 2] and [1, 2].

For the forth element 3, if we append it to some arithmetic subsequences ending with 2, these subsequences must have a common difference of 3 - 2 = 1. Indeed there are two: [1, 2] and [1, 2]. So we can append 3 to the end of these subsequences, and the answer is added by 2. Similar to above, it can form new weak arithmetic subsequences [1, 3], [1, 3] and [2, 3].

The other elements are the same, we can view the process in the figure below. The red bracket indicates the weak arithmetic subsequence of length 2, and the black bracket indicates the arithmetic subsequence. The answer should be the total number of black brackets.​
