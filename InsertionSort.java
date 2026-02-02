package ed260bubblesort;

public class InsertionSort {

    public static void main(String[] args) {
        int arr[] = {5,3,8,4,2};
        insertionSort(arr);
        mostrar(arr);
    }

    public static void insertionSort(int[] arr){
        for(int i = 1; i < arr.length; i++){
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void mostrar(int[] arr){
        for(int x : arr) System.out.print(x + " ");
        System.out.println();
    }
}


Insertion Sort ordena el arreglo construyendo una parte ordenada elemento por elemento. En cada iteración, toma un valor y lo inserta en la posición correcta dentro de la sección ya ordenada. Es eficiente para arreglos pequeños o casi ordenados y tiene una implementación sencilla.