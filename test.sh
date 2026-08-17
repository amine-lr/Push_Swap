echo "== Build =="
#!/bin/sh
# Regression test for push_swap
echo "== Build =="
make

echo
echo "== Functional tests =="

cat > /tmp/push_cmds.txt <<'CMDS'
./push_swap --bench 1 2 3 4 5
./push_swap --bench 3 2 1
./push_swap --bench 1 2 3 4 5 6 7 8 9 10
./push_swap --bench 10 9 8 7 6 5 4 3 2 1
./push_swap --simple --bench 10 9 8 7 6 5 4 3 2 1
./push_swap --medium --bench 10 9 8 7 6 5 4 3 2 1
./push_swap --complex --bench 10 9 8 7 6 5 4 3 2 1
./push_swap --bench 2
./push_swap --bench 0
./push_swap --bench 1 1 2
./push_swap --bench 2147483648
CMDS

while IFS= read -r c || [ -n "$c" ]; do
  printf "\n--- Running: %s ---\n" "$c"
  if eval "$c"; then
    :
  else
    printf "== Command failed (exit $?): %s ==\n" "$c"
  fi
done < /tmp/push_cmds.txt

# Norminette check (if installed)
if command -v norminette >/dev/null 2>&1; then
  echo
  echo "== Norminette =="
  norminette .
else
  echo
  echo "Norminette not found; skipping style checks."
fi
