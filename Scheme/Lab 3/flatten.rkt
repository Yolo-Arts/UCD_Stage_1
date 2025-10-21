#lang racket

(define flatten
  (lambda (L)
    (cond ( (equal? (length L) 0)    '()     )
          ( (list? (car L))   (append (car L) (flatten (cdr L)) )                    )
          ( #t (cons (car L) (flatten (cdr L)) ) )
          )))

;; (equal? '(hi) list)
    ;; (list? '(hi) )