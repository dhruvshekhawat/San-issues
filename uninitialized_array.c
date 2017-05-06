int main(){
        int arr[30];
	arr[40] = 34;
	printf("%d\n", arr[40]);
}
/*Obvious out-of-bound memory accesses are already optimized by compiler at runtime before ASan can detect it*/
