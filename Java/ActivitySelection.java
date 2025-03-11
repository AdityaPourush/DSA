public class ActivitySelection {
    public static int activitySelection(int[] start, int[] end){
        int n = start.length;
        int currentActivity = 0;
        int activityCount = 0;

        for(int i=0; i<n; i++){
            if(end[currentActivity] <= start[i]){
                currentActivity = i;
                activityCount++;
            }
        }
        return activityCount;
    }

    public static void main(String[] args) {
        int[] start = {1, 3, 2, 5};
        int[] end = {2, 4, 3, 6};
        int tasks = activitySelection(start, end);
        System.out.println(tasks);
    }
}
