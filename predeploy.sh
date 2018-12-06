rm src/*.bs.js
rm src/example/*.bs.js
npm run build
for i in src/*.js;do sed -i '' -e 's/bs-platform/@aaronshaf\/bs-js/g' $i;done
for i in src/*/*.js;do sed -i '' -e 's/bs-platform/@aaronshaf\/bs-js/g' $i;done
