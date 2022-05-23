function main
  vars
    a 1
    b 1
    c 1
  endvars

   %1 = 13
   a = %1
   %3 = 4
   b = %3
   %6 = a / b
   %7 = %6 * b
   %5 = a - %7
   c = %5
   writei c
   %9 = '.'
   writec %9
   %10 = '\n'
   writec %10
   %11 = - a
   %13 = %11 / b
   %14 = %13 * b
   %12 = %11 - %14
   c = %12
   writei c
   %16 = '.'
   writec %16
   %17 = '\n'
   writec %17
   %18 = - b
   %20 = a / %18
   %21 = %20 * %18
   %19 = a - %21
   c = %19
   writei c
   %23 = '.'
   writec %23
   %24 = '\n'
   writec %24
   %25 = 3
   %26 = a + %25
   %28 = %26 / b
   %29 = %28 * b
   %27 = %26 - %29
   c = %27
   writei c
   %31 = '.'
   writec %31
   %32 = '\n'
   writec %32
   %33 = - a
   %34 = 3
   %35 = %33 - %34
   %36 = - b
   %38 = %35 / %36
   %39 = %38 * %36
   %37 = %35 - %39
   c = %37
   writei c
   %41 = '.'
   writec %41
   %42 = '\n'
   writec %42
   return
endfunction


