int solution(vector<int> &A) {
    // Implement your solution here
   std::sort(A.begin(), A.end());
   int count = 1;
   for (int i = 1; i < A.size(); ++i) {
       if (A[i-1] != A[i]) {
           if (count % 2) return A[i-1];
           count = 0;
       }
       ++count;
   }
   if (count % 2) return A.back();
   return -1;
}