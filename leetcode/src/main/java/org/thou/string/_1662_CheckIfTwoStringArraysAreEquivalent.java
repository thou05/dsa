package org.thou.string;

//ghep tu -> so sanh
public class _1662_CheckIfTwoStringArraysAreEquivalent {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String result1 = "";
        String result2 = "";

        for(String x : word1){
            result1 += x;
        }

        for (String x : word2){
            result2 += x;
        }

        return result1.equals(result2);
    }

    public boolean arrayStringsAreEqual2(String[] word1, String[] word2) {
        StringBuilder result1 = new StringBuilder();
        StringBuilder result2 = new StringBuilder();

        for(String x : word1){
            result1.append(x);
        }

        for (String x : word2){
            result2.append(x);
        }

        return result1.toString().equals(result2.toString());
    }



    public static void main(String[] args) {

    }
}
