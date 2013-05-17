QUESTION 1: Experiencing exec() Commands in Linux!!!
Write a program for the following.
Input File Format:
<No. of commands = N>
<Command_1> <dependency on> <environment path variable> <options>
<Command_2> <dependency on> <environment path variable> <options>
<Command_3> <dependency on> <environment path variable> <options>
.
.
.
.
<Command_N> <dependency on> <environment path variable> <options>
If the environment path variable is “–” then you need to set the path as “/bin: /sbin/: /etc/: /home/usr/”
Assumptions:

‐ You are expected to have super user privileges at all times.

‐ Each command will depend on not more than one command.

Procedure:

The main process should read the input file using filename as the argument to the main function. While reading the input file, the main process should create two 2-D character arrays arrA and arrB for storing the commands in it. The grouping should be done as mentioned in the steps below.

(A) A dependency indicates whether a command depends on any other command and must execute only after that command has finished execution. For example: If the entry says ls ps /bin/ –l This indicates that ls should execute only after ps has been executed.

(B) If a command depends on another command, it should be added to the array containing the dependency command entry. So, for the above example, ls should be added to the array that contains ps and the entry should be anywhere after the entry of ps. 

(C) If a command is not dependent on any other command, then it must be inserted into the smaller array among the two.

(D) After grouping all the commands according to Step A to Step C, you will get two 2-D arrays containing commands to be executed after satisfying all their dependencies.

(E) Now, the main process should fork two child processes.

(F) Child 1 will execute commands from arrA sequentially and Child 2 will execute commands from arrB sequentially. Child 1 and Child 2 will execute concurrently.

(G) For each command, the child processes will fork another process for the execution which will use the execv() system call to execute the command along with the environment path variable specified in the input file.

(H) Make sure you are not creating orphan process(es) while executing. i.e. all the child processes should finish before its parent terminates normally.



QUESTION 2: Wannabe Hacker !!!!

Since you are going to pursue a major in computers, you must be aware of how hacking is done (for your own benefit). We present to you a very sneaky way into “Some one’s” user space where in you can edit your own marks for your assignment. 

Aim: Change your Test 1 marks in “Some one’s” user space at your own will without any penalty.

Input Format:

The input must be taken as follows <filename> <ID No.> <New marks>
This input must be taken as arguments to the main function.

Format of the Marks file:
<ID No.> <\t> <Marks>

Assumptions:

‐ You must have super user privileges at all times.

‐ Create two groups 1.) Evaluator, 2.) Student (please refer to figure1 at the end for the exact hierarchy expected of the directories)

‐ There will be two evaluators in the evaluator group.

‐ Individual evaluator will have its own directories and subdirectories. One of them will contain your marks file.

‐ You should write your code in the Student’s directory and not in the Evaluator’s.

‐ There may be a directory of the same name as that of the file you want to search.

‐ The code will start searching the marks file from the Evaluator directory, down the hierarchy.

‐ There will be no space in the name of any file or directory.

‐ You can use ‘chdir’ system call as ‘cd’ command does not work in exec(). You must use exec() series system calls for executing the rest of the commands like ‘pwd’, ‘ls’, ‘grep’, ‘rm’.
