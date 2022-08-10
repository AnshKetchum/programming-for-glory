import java.util.Scanner;
import java.math.BigInteger;

public class AddingDigits
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        BigInteger a = BigInteger.valueOf(sc.nextInt());
        BigInteger b = BigInteger.valueOf(sc.nextInt());
        int n = sc.nextInt();
        boolean fail = false;

        for(int i = 0; i < n && !fail; i++)
        {
            fail = true;
            for(int j = 0; j < 10; j++)
            {
                BigInteger t = a.multiply(BigInteger.TEN).add(BigInteger.valueOf(j));
                if(t.mod(b).equals(BigInteger.ZERO))
                {
                    a = t; 
                    fail = false;
                    break;
                }
            }
        }

        System.out.println( (fail ? -1 : a));
        sc.close();
    }
}