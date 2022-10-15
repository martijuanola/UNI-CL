function one
  params
    _result
  endparams

   %1 = 1
   _result = %1
   return
endfunction

function sort
  params
    v
  endparams

  vars
    i 1
    j 1
    jmin 1
    aux 1
  endvars

     %1 = 0
     i = %1
  label beginwhile2 :
     %3 = 20
     %4 = 1
     %5 = %3 - %4
     %6 = i < %5
     ifFalse %6 goto endwhile2
     jmin = i
     %8 = 1
     %9 = i + %8
     j = %9
  label beginwhile1 :
     %11 = 20
     %12 = j < %11
     ifFalse %12 goto endwhile1
     %13 = v
     %14 = %13[j]
     %15 = v
     %16 = %15[jmin]
     %17 = %14 <. %16
     ifFalse %17 goto endif1
     jmin = j
  label endif1 :
     %19 = 1
     %20 = j + %19
     j = %20
     goto beginwhile1
  label endwhile1 :
     %22 = jmin == i
     %22 = not %22
     ifFalse %22 goto endif2
     %23 = v
     %24 = %23[i]
     aux = %24
     %26 = v
     %27 = v
     %28 = %27[jmin]
     %26[i] = %28
     %30 = v
     %30[jmin] = aux
  label endif2 :
     %32 = 1
     %33 = i + %32
     i = %33
     goto beginwhile2
  label endwhile2 :
     return
endfunction

function evenPositivesAndSort
  params
    v
  endparams

  vars
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 20
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = v
     %6 = %5[i]
     %7 = 0
     %9 = float %7
     %8 = %9 <. %6
     ifFalse %8 goto endif1
     %10 = v
     pushparam 
     call one
     popparam %11
     %10[i] = %11
  label endif1 :
     %13 = 1
     %14 = i + %13
     i = %14
     goto beginwhile1
  label endwhile1 :
     %16 = v
     pushparam %16
     call sort
     popparam 
     return
endfunction

function main
  vars
    af 20
    i 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 20
     %4 = i < %3
     ifFalse %4 goto endwhile1
     readf %5
     af[i] = %5
     %6 = 1
     %7 = i + %6
     i = %7
     goto beginwhile1
  label endwhile1 :
     %9 = &af
     pushparam %9
     call evenPositivesAndSort
     popparam 
     %10 = 0
     i = %10
  label beginwhile2 :
     %12 = 20
     %13 = i < %12
     ifFalse %13 goto endwhile2
     %14 = af[i]
     pushparam 
     call one
     popparam %15
     %16 = %14 ==. %15
     %16 = not %16
     ifFalse %16 goto else1
     %17 = af[i]
     writef %17
     %18 = ' '
     writec %18
     %19 = 1
     %20 = i + %19
     i = %20
     goto endif1
  label else1 :
     %22 = '\n'
     writec %22
     return
  label endif1 :
     goto beginwhile2
  label endwhile2 :
     %23 = '\n'
     writec %23
     return
endfunction


