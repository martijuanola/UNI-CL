function fusio
  params
    _result
    ai
    af
  endparams

  vars
    j 1
    k 1
    s 1
  endvars

     %1 = 0
     j = %1
     %3 = 0
     %4 = float %3
     s = %4
  label beginwhile1 :
     %5 = 10
     %6 = j < %5
     ifFalse %6 goto endwhile1
     %7 = 0.0
     %7 = %7 +. s
     %9 = ai
     %10 = %9[j]
     %11 = float %10
     %7 = %7 +. %11
     s = %7
     %13 = 9
     %14 = j < %13
     ifFalse %14 goto else1
     %15 = ai
     %16 = 1
     %17 = j + %16
     %18 = %15[%17]
     k = %18
     goto endif1
  label else1 :
     %20 = 0
     %21 = %20 < j
     ifFalse %21 goto else2
     %22 = ai
     %23 = 1
     %24 = j - %23
     %25 = %22[%24]
     k = %25
     goto endif2
  label else2 :
     %27 = 4
     %28 = - %27
     k = %28
  label endif2 :
  label endif1 :
     %30 = 0.0
     %30 = %30 +. s
     %32 = af
     %33 = %32[j]
     %30 = %30 +. %33
     %35 = float k
     %30 = %30 +. %35
     s = %30
     writef s
     writes "\n"
     %37 = 1
     %38 = j + %37
     j = %38
     goto beginwhile1
  label endwhile1 :
     _result = s
     return
endfunction

function main
  vars
    i 1
    z 1
    a 10
    b 10
    x 1
    c 1
    d 1
  endvars

     %1 = 0
     i = %1
  label beginwhile1 :
     %3 = 10
     %4 = i < %3
     ifFalse %4 goto endwhile1
     %5 = 2
     %6 = %5 * i
     %7 = 1
     %8 = %6 + %7
     a[i] = %8
     %10 = 10
     %11 = %10 - i
     %12 = 0
     %13 = 3
     %14 = %13 * i
     %12 = %12 + %14
     %15 = 1
     %16 = - %15
     %12 = %12 + %16
     %17 = float %12
     b[%11] = %17
     %18 = 1
     %19 = i + %18
     i = %19
     goto beginwhile1
  label endwhile1 :
     %21 = 0
     i = %21
  label beginwhile2 :
     %23 = 10
     %24 = i < %23
     ifFalse %24 goto endwhile2
     %25 = b[i]
     writef %25
     writes " "
     %26 = 1
     %27 = i + %26
     i = %27
     goto beginwhile2
  label endwhile2 :
     writes "\n"
     pushparam 
     %29 = &a
     pushparam %29
     %30 = &b
     pushparam %30
     call fusio
     popparam 
     popparam 
     popparam %31
     writef %31
     writes "\n"
     return
endfunction


