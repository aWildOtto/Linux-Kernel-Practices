# CMPT 300 Project 4

A Linux kernel programming project

## Where is the code?
This is a kernel patch. You can patch your Linux kernel using the patch.diff file so your kernel have two awesome(?) new  custom system calls as described below. In fact paying attention to the file you can find the C code within

## This project includes two custom Linux system call
- array_stats
returns a struct containing the max, min and sum in an array
(which is completely unnecessary to write but this is meant to be a kernel exploration)
- process_ancestors
returns a struct containing information on the current running process
	* long pid; /* Process ID */
	* char name[ANCESTOR_NAME_LEN]; /* Program name of process */
	* long state; /* Current process state */
	* long uid; /* User ID of process owner */
	* long nvcsw; /* # voluntary context switches */
	* long nivcsw; /* # involuntary context switches */
	* long num_children; /* # children process has */
	* long num_siblings; /* # sibling process has */

Zhixuan(Otto) Hu & Ming-Nu Lee



Linux kernel version used: 4.9.9
64-bit


