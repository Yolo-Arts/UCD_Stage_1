#lang racket

(define L '( (1 2 3) (4 5) (6 7) (8 9 10) (11 12) (13 14 15) (16 17 18) (19 20) ))

;; filter

(define hasTwoMembers?
  (lambda (E)
    (equal? (length E) 2)
    ))

;; (filter hasTwoMembers? L)
;; (filter (lambda(E) (equal? (length E) 2) ) L)
;; '((4 5) (6 7) (11 12) (19 20))

(define hasLength
  (lambda (len)
    (lambda (E)
      (equal? (length E) len)
    )))

;; (define hasLength (lambda(len) (lambda(E) (equal? (length E) len) ) ) )

;; APPLY
(define sumUpList
  (lambda (E)
    (apply + E)
    ))
;; (map sumUpList L)
;; '(6 9 13 27 23 42 51 39)

;; (map (lambda(E) (apply + E)) L)

(define fnUpList
  (lambda (fn)
  (lambda (E)
    (apply fn E)
    )))

;; (map (fnUpList *) L)
;; '(6 20 42 720 132 2730 4896 380)