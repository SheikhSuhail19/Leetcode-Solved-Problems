# Alex Travelling
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Alex is very fond of travelling. He decided to visit <strong>n </strong>cities,labeled from<strong> 1</strong> to<strong> n</strong>.&nbsp;&nbsp;You are also given flights, a list of travel flights as directed edges<strong> flights[i] = (u<sub>i</sub>,v<sub>i</sub>,w<sub>i</sub>)</strong>&nbsp;where<strong> u<sub>i&nbsp;</sub></strong>is the source node,<strong> v<sub>i</sub>&nbsp;</strong>is the target node, and <strong>w<sub>i</sub></strong>&nbsp;is the price it takes for a signal to travel from source to target.</span></p>

<p><span style="font-size:18px">Alex started to travel from a given&nbsp;node <strong>k</strong>. Return&nbsp;the<strong>&nbsp;minimum&nbsp;</strong>cost&nbsp;it takes Alex for all the<strong> n</strong>&nbsp;nodes to cover. If it is impossible for all the <strong>n</strong>&nbsp;nodes to cover, return -1.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N: 4
k: 2
flights size: 3
flights: [[2,1,1],[2,3,1],[3,4,1]]
<strong>Output:</strong>
2
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N: 2
k: 1
flights: [[1,2,1]]
<strong>Output:</strong>
1

</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">You don't need to print or input anything. Complete the function <strong>minimumCost()&nbsp;</strong>which takes a&nbsp; flights array, an integer n and an integer k<strong>&nbsp;</strong>as the input parameters and returns an integer, denoting <strong>&nbsp;the minimum&nbsp;</strong>cost&nbsp;it takes to cover all n nodes.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong></span></p>

<ul>
	<li><span style="font-size:18px">1 &lt;= k &lt;= n &lt;= 100</span></li>
	<li><span style="font-size:18px">1 &lt;= times.length &lt;= 6000</span></li>
	<li><span style="font-size:18px">times[i].length == 3</span></li>
	<li><span style="font-size:18px">1 &lt;= u<sub>i</sub>, v<sub>i</sub>&nbsp;&lt;= n</span></li>
	<li><span style="font-size:18px">u<sub>i</sub>&nbsp;!= v<sub>i</sub></span></li>
	<li><span style="font-size:18px">0 &lt;= w<sub>i</sub>&nbsp;&lt;= 100</span></li>
	<li><span style="font-size:18px">All the pairs&nbsp;(u<sub>i</sub>, v<sub>i</sub>)&nbsp;are&nbsp;<strong>unique</strong>. (i.e., no multiple edges)</span></li>
</ul>
</div>