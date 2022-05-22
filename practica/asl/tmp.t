function fact
  params
    _result
    n
  endparams

  vars
    f 1
  endvars

     %1 = 1
     f = %1
  label beginwhile1 :
     %3 = 1
     %4 = %3 < n
     ifFalse %4 goto endwhile1
     %5 = f * n
     f = %5
     %7 = 1
     %8 = n - %7
     n = %8
     goto beginwhile1
  label endwhile1 :
     _result = f
     return
endfunction

function main
  vars
    max 1
    i 1
    f 1
    end 1
  endvars

     %1 = 0
     i = %1
     %3 = 1
     end = %3
     readi %5
     max = %5
     %6 = i <= max
     ifFalse %6 goto endif1
     %7 = 0
     end = %7
  label endif1 :
  label beginwhile1 :
     %9 = not end
     ifFalse %9 goto endwhile1
     writei i
     writes "!="
     pushparam 
     pushparam i
     call fact
     popparam 
     popparam %10
     writei %10
     writes "\n"
     %11 = i == max
     ifFalse %11 goto endif2
     %12 = 1
     end = %12
  label endif2 :
     goto beginwhile1
  label endwhile1 :
     return
endfunction


