; Partition all elements of a linked list around n, such that all nodes before n are less than or equal to n

(let
  (
    (linked_list '(nil))
    (partition_around 0)
    (smaller '(nil))
    (larger '(nil))
    (final '(nil))
  )
  (
    loop for x from 1 upto 100
    do (
      push (random x) linked_list
    )
  )

  (setq partition_around (nth (random (length linked_list)) linked_list))

  (
    loop for x from 1 upto (- (length linked_list) 2)
    do (
      if (>= partition_around (nth x linked_list))
        (
          push (nth x linked_list) smaller
        )
        (
          push (nth x linked_list) larger
        )
    )
  )

  (print smaller)
  (print partition_around)
  (print larger)
)
