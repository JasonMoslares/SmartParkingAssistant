import React from 'react'
import { BrowserRouter, Routes, Route} from 'react-router-dom'
import Home from '../../Pages/Home'
import Create from '../../Pages/Create'
import Update from '../../Pages/Update'
import 'bootstrap/dist/css/bootstrap.min.css'

function App(){
  return (
    <BrowserRouter>
      <Routes>
        <Route path='/' element={<Home />} />
        <Route path='/create' element={<Create />} />
        <Route path='/edit/:id' element={<Update />} />
      </Routes>
    </BrowserRouter>
  )
}

export default App;
