package javaapplication3;

public class MSorter extends Thread{
    private int[] arr;
    private int Size;
    private int left;
    private int right;
    public int[] resArr ;
    public MSorter(int[] arr, int i, int j) {
        this.arr = arr;
        this.Size = arr.length;
        //this.resArr = new int[j-i+1];
        this.left  = i;
        this.right = j;
    }
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
        if(left==right)
            this.resArr = new int[]{arr[left]};
        else if(left<right){
            int rtlim = this.left+(right-left)/2;
            MSorter mleft = new MSorter(arr,left,rtlim);
            mleft.start();
            int ltlim = 1 + rtlim;            
            MSorter mright = new MSorter(arr,ltlim,right);  
            mright.start();
            try {
                mleft.join();
                mright.join();
            }catch (InterruptedException e) {}
            Merger mrg = new Merger(mleft.resArr,mright.resArr);
            mrg.start();
            try {
                mrg.join();
            }catch (InterruptedException e) {}
            resArr=mrg.res_arr;
        }
    }
}
