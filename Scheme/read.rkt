#lang racket

; read eval print loop

(define talk
  (lambda()
    (display "What are your wishes? ")
    (define gotSomething (read))
    (cond ( (equal? gotSomething 'stop) 'goodbye)
          ( #t (display "that's ") (display (eval gotSomething))(display "\n")  (talk) )
          )))
