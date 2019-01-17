rm src/*.bs.js
rm example/*.bs.js
yarn build
for i in src/*.js;do sed -i '' -e 's/bs-platform/@aaronshaf\/bs-js/g' $i;done
for i in example/*.js;do sed -i '' -e 's/bs-platform/@aaronshaf\/bs-js/g' $i;done
