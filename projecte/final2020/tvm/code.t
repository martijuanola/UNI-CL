function f
  params
    _result
    a
    b
  endparams

  vars
    x 1
    y 1
    z 10
  endvars

     %1 = 67
     %2 = a + %1
     z = %2
     %3 = 34
     x = %3
     %4 = 56
     %5 = 9
     %6 = z[%5]
     %7 = %4 + %6
     z = %7
     %8 = 3
     %9 = z[%8]
     %11 = float %9
     %10 = b <. %11
     ifFalse %10 goto endif1
     %12 = 78
     x = %12
     writef b
     writes "\n"
  label endif1 :
     %13 = 3
     %14 = z[%13]
     writei %14
     writes "\n"
     %15 = 1
     _result = %15
     return
endfunction

function fz
  params
    r
  endparams

  label beginwhile1 :
     %1 = 0
     %2 = %1 < r
     ifFalse %2 goto endwhile1
     %3 = 1
     %4 = r - %3
     r = %4
     goto beginwhile1
  label endwhile1 :
     return
endfunction

function main
  vars
    a 1
  endvars

     pushparam 
     %1 = 3
     pushparam %1
     %2 = 2
     %3 = float %2
     pushparam %3
     call f
     popparam 
     popparam 
     popparam %4
     ifFalse %4 goto endif1
     %5 = 3.7
     %7 = float a
     %6 = %7 +. %5
     %8 = 4
     %10 = float %8
     %9 = %6 +. %10
     writef %9
     writes "\n"
  label endif1 :
     return
endfunction


