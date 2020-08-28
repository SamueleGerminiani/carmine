//Checker for G(a->Xb)
//Return true if checker did not fail
inline bool checker(bool p0, bool p1, bool const reset = false){
   static int NEXT_STATE = 0;
   if(reset){
      NEXT_STATE = 0;
    }
   switch(NEXT_STATE){

      case 0:
         if(!p0){
            NEXT_STATE = 0;
         }
         if(p0){
            NEXT_STATE = 1;
         }
         break;

      case 1:
         if((!p0 && p1)){
            NEXT_STATE = 0;
         }
         if((p0 && p1)){
            NEXT_STATE = 1;
         }
         if(!p1){
            return false;
         }
         break;
   }

   return true;
}
