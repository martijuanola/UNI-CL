function dumpi
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

function dumpf
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
     writef %6
     writes " "
     %7 = 1
     %8 = i + %7
     i = %8
     goto beginwhile1
  label endwhile1 :
     writes "\n"
     return
endfunction

function toreal
  params
    _result
    x
  endparams

   %1 = 1.3
   %3 = float x
   %2 = %3 *. %1
   _result = %2
   return
endfunction

function getint
  params
    _result
    x
  endparams

     %1 = 10
     %3 = float %1
     %2 = x <. %3
     ifFalse %2 goto endif1
     %4 = 10
     _result = %4
     return
  label endif1 :
     %5 = 20
     %7 = float %5
     %6 = x <. %7
     ifFalse %6 goto endif2
     %8 = 20
     _result = %8
     return
  label endif2 :
     %9 = 50
     %11 = float %9
     %10 = x <. %11
     ifFalse %10 goto endif3
     %12 = 50
     _result = %12
     return
  label endif3 :
     %13 = 100
     %15 = float %13
     %14 = x <. %15
     ifFalse %14 goto endif4
     %16 = 100
     _result = %16
     return
  label endif4 :
     %17 = 500
     _result = %17
     return
endfunction

function main
  vars
    a 10
    c 10
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = 10
     %6 = %5 * i
     a[i] = %6
     %8 = 77
     %9 = float %8
     c[i] = %9
     %10 = 1
     %11 = i + %10
     i = %11
     goto beginwhile1
  label endwhile1 :
     writes "a: "
     %13 = &a
     pushparam %13
     call dumpi
     popparam 
     %14 = 1
     %15 = 0
     %17 = 10
  label beginMap2 :
     %16 = %15 < %17
     ifFalse %16 goto endMap2
     pushparam 
     %18 = a[%15]
     pushparam %18
     call toreal
     popparam 
     popparam %19
     c[%15] = %19
     %15 = %15 + %14
     goto beginMap2
  label endMap2 :
     writes "c: "
     %22 = &c
     pushparam %22
     call dumpf
     popparam 
     %23 = 1
     %24 = 0
     %26 = 10
  label beginMap3 :
     %25 = %24 < %26
     ifFalse %25 goto endMap3
     pushparam 
     %27 = c[%24]
     pushparam %27
     call getint
     popparam 
     popparam %28
     a[%24] = %28
     %24 = %24 + %23
     goto beginMap3
  label endMap3 :
     writes "a: "
     %31 = &a
     pushparam %31
     call dumpi
     popparam 
     %32 = 1
     %33 = 0
     %35 = 10
  label beginMap4 :
     %34 = %33 < %35
     ifFalse %34 goto endMap4
     pushparam 
     %36 = a[%33]
     %38 = float %36
     pushparam %38
     call getint
     popparam 
     popparam %37
     c[%33] = %37
     %33 = %33 + %32
     goto beginMap4
  label endMap4 :
     writes "c: "
     %40 = &c
     pushparam %40
     call dumpf
     popparam 
     return
endfunction


