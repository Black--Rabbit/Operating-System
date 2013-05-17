QUESTION 1: From Spiderman to the Avengers!!!

Nick Fury has put a team together to get a hold of the stolen Tesseract. Using clues obtained by Gamma radiations from Tesseract, intelligent Bruce Banner and Tony Stark have provided Fury with a sequence of clues about the location. Each digit in the clue enables each member to search the location efficiently. Using the sequence Nick Fury wants an immediate result on the location of the Tesseract. Find out whether the clues sequence can successfully identify the location or not. For faster and efficient interpretation of the clues sequence, the following plan has been devised.

o  NxN matrix with entries from 0 to 9 denoting available locations where (0,0) entry is location of the Avengers and (N-1, N-1) is location of Tesseract.

o  And array of clues with each entry between 0 to 9.

Write a program to determine whether the given array sequence finds the final location or not. The sequence is said to be valid iff there exists at least one path from (0, 0) to (N-1, N-1) that covers all the digits in the given sequence in the same order as they appear. Meaning, (0, 0) entry in matrix entry should match with 0th digit of the sequence. (0,1) or (1,0) or (1,1) entry in the matrix matches with 1st digit and so on till (N-1, N-1) entry matches with the last digit of the sequence. You are expected to create threads for each entry in the matrix to ensure parallel scanning.

Procedure:

‐ The main thread will read the entries in the matrix and will check for the first entry of the matrix with the first entry of the array. If it matches, three threads will be created. 

o First one will check the entry to the right of the current entry.

o Second one will check the entry below the current entry.

o Third will check the entry diagonal to the current entry.

If the entry doesn’t match, the thread will terminate and returns termination status. For, each entry of the matrix, the same above step will take place. If the entry is valid at (i,j), we will have three threads that will verify the (i+1,j), (i,j+1) and (i+1,j+1) entries if at all these entries exist. For boundary cases, i.e. the last row and the last column the cases should be handled properly and no extra threads should be created. The threads should keep on executing till either a valid path is found or an invalid entry is encountered. Corresponding to each condition, respective values should be returned while exiting (1 for a success and 0 for a failure). The parent thread should use this status to verify the existence of the path. If the path exists i.e. (N-1, N-1) entry matched with the last element of the sequence, then all such paths should be printed. Output: The output must be printed in reverse order where in each thread participating in the actual path prints its (i,j) pair.



QUESTION 2: Experiencing Parallel Programming with Threads

Write a program to multiply N complex numbers using threads.
Input File Format:
<No. of complex numbers = N>
<Complex No. 0>
<Complex No. 1>
<Complex No. 2>
:
:
<Complex No. N-1>
The complex number will be of the form “a+ib” where a and b are integers.
For e.g.
1 + i2 (a = 1, b = 2)
1 + i-1 (a = 1, b = -1)
-1 + i4 (a = -1, b = 4)
Procedure:
Each complex number is stored as a structure with a real and an imaginary integer member in it. The main thread should read N complex numbers from the file and store it as D[N] an array of structure in global data space. The program should do the following 

‐ Create [floor (N/2)] number of threads from the main thread

o Each thread will compute product of (2*i)th input and (2*i +1)th input where i is the thread number [0 to [floor (N/2)]-1]. The product is stored in temporary output array in global space. If N is an even number, the number of threads created for computation is equal to N/2 and the temporary output array elements will be equal to N/2. If N is an odd number, the number of threads created for computation is equal to [floor (N/2)] and the temporary output array elements will be equal to [ceil (N/2)]. This is because the last input is transferred directly as output for the next processing.

o After these [floor (N/2)] threads exit, the main process will print the intermediate results and will use this as the next input for the processing.

o This process will continue till we get the final result, i.e., the number of elements in inter mediate output is exactly 1.

o Print the final result from the main thread.

