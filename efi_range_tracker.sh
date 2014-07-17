#/bin/bash
while true do
  clear echo
  date start=`date +%s -d "Wed Jan 16 17:46:00"`
  current=`date +%s`
  echo "Current PIN Between: " | tr '\n' ' '
  echo "($current - $start) / 19.782" | bc | tr '\n' ' '
  echo " and " | tr '\n' ' '
  echo "($current - $start) / 18.782" | bc
  sleep 2
done
