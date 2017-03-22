<tbody><tr>
<td colspan="2" align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>    variables
        wants_to_enter : array of 2 booleans
        turn : integer

    wants_to_enter[0] ← false
    wants_to_enter[1] ← false
    turn ← 0   // or 1
</pre></div>
</td>
</tr>
<tr>
<td align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>p0:
   wants_to_enter[0] ← true
   while wants_to_enter[1] {
      if turn ≠ 0 {
         wants_to_enter[0] ← false
         while turn ≠ 0 {
           // busy wait
         }
         wants_to_enter[0] ← true
      }
   }

   // critical section
   ...
   turn ← 1
   wants_to_enter[0] ← false
   // remainder section
</pre></div>
</td>
<td align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>p1:
   wants_to_enter[1] ← true
   while wants_to_enter[0] {
      if turn ≠ 1 {
         wants_to_enter[1] ← false
         while turn ≠ 1 {
           // busy wait
         }
         wants_to_enter[1] ← true
      }
   }
 
   // critical section
   ...
   turn ← 0
   wants_to_enter[1] ← false
   // remainder section
</pre></div>
</td>
</tr>
</tbody>
