# DANTE
<h1>B-CPE-200-MAR-2-1-dante-vincent.montero-fontaine</h1>

<h2>To do:</h2>
<p>
<li>The goal of this project is to generate mazes (in a reasonable amount of time), solve them (in a reasonable
amount of time), and print the solution.</li><br>
<li>It has 2 folders : solver with a binary named “solver” in it, generator with binary named “generator”
in it. Each folder contains a Makefile compiling the binary and a Makefile at the root compiles all binaries.</li><br>
</p>

<h2>What is a maze ?</h2>
<p>Here is the maze format description:</p>
<li>Mazes are rectangular.</li>
<li>They are coded in ASCII.</li>
<li>The ‘X’s represent the walls and the’*’s represent the free spaces.</li>
<li>It is possible to move to the four surrounding squares (up, down, right, left).</li>
<li>“Start” is in the upper left-hand corner (0;0)</li>
<li>“Finish” is in the bottom right-hand corner.</li>
<li>A solution is a series of free, adjacent squares, from “Start” to “Finish” included.</li>
<li>“Start” and “Finish” can be occupied. In this case, there is no solution.</li>
<li>The last line of the maze doesn’t terminate with a return line.</li>
<li>Resolution: in order to write the solution in the maze, we use ‘o’ for the solution path.</li>

<p>This project used weighted graph to solve a maze. We used recursive backtracking as the generator algorithm and A* as the solver.</p>

<p>System functions and libC are allowed for this project, but no external libraries.</p>

<h2> How to test it ? </h2>

<p><code>make</code> and then do <code>./generator/generator ROWS COLS perfect/imperfect</code> (imperfect by default) and <code>./solver/solver MAP</code></p>

<p> To redirect a file, just do <code>./generator/generator ROWS COLS > NAME.txt</code></p>
<p>You also have a tester.sh file at your disposition, just use it like this: <code>./tester.sh ROWS COLS perfect/imperfect</code></p>
<p>With ROWS and COLS being sizes of the maze you want to write, the file will then generate and then print the solved maze, with the path shown with red os</p>
<br><br>

Our team !
| [<img src="https://github.com/Joan-R.png?size=85" width=85><br><sub>Joan Ruiz</sub>](https://github.com/Joan-R) | [<img src="https://github.com/Priax.png?size=85" width=85><br><sub>Vincent Montero Fontaine</sub>](https://github.com/Priax)
| :---: | :---: |
