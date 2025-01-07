// Problem Statement: Given an array ‘arr of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
import java.util.*;

public class BinarySearchBookAllocation {
    
    public static int studentCountToRead(ArrayList<Integer> bookPages, int m, int maxPages){
        int n = bookPages.size();
        int currPageCount = 0;
        int studentCount = 1;
        for(int i=0; i<n; i++){
            if(currPageCount + bookPages.get(i) > maxPages){
                studentCount++;
                currPageCount = bookPages.get(i);
            }
            else {
                currPageCount += bookPages.get(i);
            }
        }
        return studentCount;
    }

    public static int minMaxPages(ArrayList<Integer> bookPages, int m){
        int n = bookPages.size();
        // if students greater than no of books, cannot distribute books
        if(m > n){
            return -1;
        }
        // min and max range of pages read
        int maxi = Collections.max(bookPages); // least no of max pages if one student gets one book
        int sum = 0; // max no of pages if only one student gets all the books
        for(int i=0; i<n; i++){
            sum += bookPages.get(i);
        }

        // binary search
        int low = maxi;
        int high = sum;
        int ans = -1;
        while(low <= high){
            int mid = low + ((high - low)/2);
            int minStudentRequired = studentCountToRead(bookPages, m, mid); // minimum no of students required to read n books, with total 'sum' pages each with max of 'mid' pages.
            if(minStudentRequired <= m){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> bookPages = new ArrayList<>();
        for(int i=0; i<n; i++){
            bookPages.add(sc.nextInt());
        }
        int m = sc.nextInt();
        int maxPages = minMaxPages(bookPages, m);
        System.out.println(maxPages);
    }
}
