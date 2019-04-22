package javaapplication3;
import java.util.Random; 


public class JavaApplication3 {

    public static void main(String[] args) {
        Random rand = new Random();
        int[] arr = new int[100];
        for (int i=0; i<arr.length; i++)
            arr[i] = rand.nextInt(1000);
        MSorter mr = new MSorter(arr,0,arr.length-1);
        mr.start();
        try {
            mr.join();
        } catch (InterruptedException e) {}
        for (int i :mr.resArr)
                System.out.print(i+" ");
    }
    
}
