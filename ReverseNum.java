import java.util.Scanner;

public class ReverseNum
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		// Count total digits in a number
		int length = String.valueOf(num).length();
		int rev=0;
		while(num>0)
		{
			int temp = num%10;
			length--;
			rev += (int) (temp*Math.pow(10, length));
			num=num/10;
		}
		System.out.println(rev);
	
		
	}
}
