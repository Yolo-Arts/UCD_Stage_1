#lang racket

(define square
  (lambda (x)
    (* x x)
    )
  )



(define hypotenuse
  (lambda (x y)
    (sqrt
     (+
      (square x)
      (square y)
      )
     )
    )
  )
