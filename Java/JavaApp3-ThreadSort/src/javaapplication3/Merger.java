package javaapplication3;

public class Merger extends Thread{
    private int[] left;
    private int[] right;
    public int[] res_arr;
    private int l=0;
    private int r=0;
    public Merger(int[] left, int[] right) {
        this.left = left;
        this.right = right;
        res_arr = new int[left.length+right.length];
    }
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
        while(l<left.length && r<right.length) {   
            if(left[l] < right[r]){
                res_arr[l+r] = left[l];
                l++;
            }
            else {
                res_arr[l+r] = right[r];
                r++;
            }
        }   
        while(l<left.length){
            res_arr[l+r] = left[l];
            l++;
        }       
        while(r<right.length){
            res_arr[l+r] = right[r];
            r++;
        }       
    }
}
