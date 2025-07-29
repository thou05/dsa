package org.thou.array;

public class _941_ValidMountainArray {
    public boolean validMountainArray(int[] arr) {
        if(arr.length < 3){
            return false;
        }
        boolean isIncreasing = true;
        for (int i = 0; i < arr.length - 1; i++) {
            int j = i + 1;
            if(arr[i] > arr[j]) {  //giam
                if (i == 0) {
                    return false;  //ngay tu dau giam la sai luon
                }
                if (isIncreasing) {
                    isIncreasing = false;  //bao hieu doi chieu
                }
            }else if(arr[i] < arr[j]) {  //tang
                if(!isIncreasing){
                    return false;
                }
            }else {  //bang nhau
                return false;
            }
        }
        if (!isIncreasing){   //day dang xet cuoi la day giam
            return true;
        }

        return false;
    }

    //cach 2, sau nghien cuu them
    public boolean validMountainArray2(int[] arr) {
        if(arr.length <3){
            return false;
        }
        int i=0;
        while(i<arr.length-1 && arr[i]<arr[i+1]){
            i++;
        }
        if(i == 0 || i ==arr.length-1 ){
            return false;
        }
        while(i<arr.length-1 && arr[i]>arr[i+1]){
            i++;
        }
        if(i == arr.length-1) {
            return true;
        };

        return false;
    }
}
