/**
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

long TIME_ELAPSED = 0;

/* This function is called when the module is loaded. */
static int simple_init(void)
{
       printk(KERN_INFO "Loading Module\n");
       // print the golden ratio prime    
       printk(KERN_INFO "%lu\n", GOLDEN_RATIO_PRIME);
       // print the current jiffies
       printk(KERN_INFO "%lu\n", jiffies);
       // set the time elapsed to the current jiffies
       TIME_ELAPSED = jiffies;
       // print the HZ
       printk(KERN_INFO "%lu\n", HZ);

       return 0;
}

/* This function is called when the module is removed. */
static void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
       // print the gcd of 3300 and 24
       unsigned long result = gcd(3300, 24);
       // print the result
       printk(KERN_INFO "Result for gcd operation: %lu\n", result);
       // print the current jiffies
       printk(KERN_INFO "%lu\n", jiffies);
       // set the time elapsed to the current jiffies minus the time elapsed
       TIME_ELAPSED = jiffies - TIME_ELAPSED;
       // print the time elapsed in seconds
       printk(KERN_INFO "Time elapsed: %lu seconds\n", TIME_ELAPSED/HZ);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

