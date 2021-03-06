#include<linux/module.h>
#include<linux/moduleparam.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Saif Ahmed Khan");

static int n=0,sum=0;
static int array[70];
static int arr_argc=0;

module_param(n,int,0);
module_param_array(array,int,&arr_argc,0000);

static int sum_init(void)
{
	int i;
	printk(KERN_INFO "Series for summation is :");
	for(i=0;i<n;i++)
	{
		sum=sum+array[i];
		printk(KERN_INFO " %d ",array[i]);	
	}	
	printk(KERN_INFO "Sum of above series is:%d\n\n\n",sum);
	return 0;
}

static void sum_exit(void)
{
	printk(KERN_INFO "Goodbye World\n");
}

module_init(sum_init);
module_exit(sum_exit);
