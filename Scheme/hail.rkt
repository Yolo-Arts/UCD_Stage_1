#lang racket

(define hail
  (lambda (n)
    (if (even? n)
        (/ n 2)
        (+ n 1)
        )
    )
)

(define hailstone
  (lambda (n num)
    (cond ( (= num 1) (hail n) )
          ( (> num 1) (hail (n))

                      )
          )
    )
  )
  