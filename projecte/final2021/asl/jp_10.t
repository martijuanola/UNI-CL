function tres
  params
    _result
    a
  endparams

   %1 = 3
   _result = %1
   return
endfunction

function dump
  params
    a
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = a
     %6 = %5[i]
     writei %6
     writes " "
     %7 = 1
     %8 = i + %7
     i = %8
     goto beginwhile1
  label endwhile1 :
     writes "\n"
     return
endfunction

function main
  vars
    a 10
    b 10
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = 3
     a[i] = %5
     %7 = 77
     b[i] = %7
     %9 = 1
     %10 = i + %9
     i = %10
     goto beginwhile1
  label endwhile1 :
     %12 = 1
     %13 = 0
     %15 = 10
  label beginMap2 :
     %14 = %13 < %15
     ifFalse %14 goto endMap2
     pushparam 
     %16 = a[%13]
     pushparam %16
     call tres
     popparam 
     popparam %17
     a[%13] = %17
     %13 = %13 + %12
     goto beginMap2
  label endMap2 :
     %18 = &b
     pushparam %18
     call dump
     popparam 
     return
endfunction


