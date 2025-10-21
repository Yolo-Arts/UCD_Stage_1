#lang racket

;; given a list of things L = '(a b c)  give back a list of all permutations of those things.
;; (perms '(a b c)) = '( (a b c) (a c b) (b a c) (b c a) (c a b) (c b a) )

(define perms
  (lambda (L)
    (cond ( (equal? (length L) 0)       '()      )
          ( (equal? (length L) 1)     (cons  (car L) '() ) )
          ( #t                      (helper (car L) (permute (cdr L)) ) )
          )))

(define helper
  (lambda (first rest)
    (cond ( () )
          ( () )
          )))