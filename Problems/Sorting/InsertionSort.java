import java.util.Scanner;

class InsertionSort
{
	public static void main(String[] args)
	{
		int[] a;
		int n;
		Scanner s = new Scanner(System.in);
		System.out.print("Enter number of elements : ");
		n = s.nextInt();
		a = new int[n];
		System.out.print("Enter the array : ");
		for(int i=0;i<n;i++)
			a[i] = s.nextInt();
		insertionSort(a);
		System.out.print("Sorted array : ");
		for(int i:a)
			System.out.print(" "+i);
	}
	private static void insertionSort(int[] a)
	{
		for(int j=1, i; j<a.length; j++)
		{
			int key = a[j];
			for(i=j-1; i>=0 && a[i] > key; i--)
				a[i+1] = a[i];
			a[i+1] = key;
		}
	}
}
