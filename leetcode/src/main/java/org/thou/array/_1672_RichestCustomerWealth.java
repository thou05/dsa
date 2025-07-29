package org.thou.array;

//tong hang i = tai san cua khach hang i
//b1: tinh tong i
//b2: tim max tong i

public class _1672_RichestCustomerWealth {
    public static int maximumWealth(int[][] accounts) {
        int numCustomer = accounts.length;
        int numBank = accounts[0].length;

        int[] sum = new int[numCustomer];

        for (int i = 0; i < numCustomer; i++){
            int count = 0;
            for (int j = 0; j < numBank; j++){
                count += accounts[i][j];
            }
            sum[i] = count;
        }

        int max = sum[0];
        for (int i = 1; i < numCustomer; i++){
            if(sum[i] > max){
                max = sum[i];
            }
        }

        return max;
    }

    //do ton bo nho hon
    public static int maximumWealth2(int[][] accounts) {
        int numCustomer = accounts.length;
        int numBank = accounts[0].length;

        int max = 0;

        for (int i = 0; i < numCustomer; i++){
            int count = 0;
            for (int j = 0; j < numBank; j++){
                count += accounts[i][j];
            }
            if(count > max){
                max = count;
            }
        }

        return max;
    }


    public static void main(String[] args) {
        int[][] a = {{1, 2, 3}, {8, 2, 1}};
        int[][] b = new int[2][3];

        System.out.println(maximumWealth(a));


//        int soHang = a.length;
//        int soCot = a[0].length;
//        System.out.println("so hang va so cot" + soHang + soCot);
    }
}
