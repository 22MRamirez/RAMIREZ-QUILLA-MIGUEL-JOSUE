package ed260bubblesort;

public class SelectionSort {

    public static void main(String[] args) {
        int arr[] = {5,3,8,4,2};
        selectionSort(arr);
        mostrar(arr);
    }

    public static void selectionSort(int[] arr){
        for(int i = 0; i < arr.length - 1; i++){
            int min = i;
            for(int j = i + 1; j < arr.length; j++){
                if(arr[j] < arr[min]){
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    public static void mostrar(int[] arr){
        for(int x : arr) System.out.print(x + " ");
        System.out.println();
    }
}


Selection Sort funciona seleccionando repetidamente el elemento más pequeño del arreglo y colocándolo en su posición correcta. Divide el arreglo en una parte ordenada y otra desordenada. Aunque siempre realiza el mismo número de comparaciones, su implementación es simple, pero no es eficiente para grandes conjuntos de datos.