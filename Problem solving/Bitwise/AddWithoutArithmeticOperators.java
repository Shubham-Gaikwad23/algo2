import java.util.Scanner;


public class AddWithoutArithmeticOperators
{
	public static void main(String[] args)
	{
		long num1, num2, pos=1, ans=0;
		boolean cin, cout, sum;
		Scanner s = new Scanner(System.in);
		num1 = s.nextLong();
		num2 = s.nextLong();
		
		for(pos=1, cin=false; pos!=0; pos=pos<<1)
		{
			boolean a, b;
			if((num1&pos)==0)
				a=false;
			else
				a=true;
			if((num2&pos)==0)
				b=false;
			else
				b=true;
			
			sum  = a ^ b ^ cin;
			cout = b&&cin || a&(b||cin);    // cout = bcin + ab + acin

			if(sum)
				ans = ans | pos;
			cin=cout;
		}
		System.out.println(ans);
	}
}
