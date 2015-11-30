/* Given array is Square (n*n)
 * And we will reverse in clockwise direction
 * and we will do it layer by layer
 */

class Reverse
{
	private static void Reverse_array(int[][] a, int n) 
	{
		for(int layer=0;layer<n/2;layer++)
		{
			int first = layer; // 0
			int last = n - layer - 1; // 2
			for(int i= first; i<last;i++)
			{
				int offset = i - first; // 0
				int top = a[first][i];
				a[first][i] = a[last-offset][first];
				a[last-offset][first] = a[last][last-offset];
				a[last][last-offset] = a[i][last];
				a[i][last] = top;
			}
		}
	}
	public static void main(String arg[])
	{
		int a[][] = {{1,2,3},{4,5,6},{7,8,9}};
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
					System.out.print(a[i][j]);
				
			}
			System.out.println();
		}
		Reverse_array(a, a.length);
		System.out.println("after reverse");
	
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
					System.out.print(a[i][j]);
				
			}
			System.out.println();
		}
		
	}
}
