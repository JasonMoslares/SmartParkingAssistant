import React, { useEffect, useState } from 'react'
import { Link, useParams } from 'react-router-dom';
import axios from 'axios'

function Read(){
    const {id} = useParams();
    const [photosensor, setPhotosensor] = useState([])
    useEffect(()=> {
        axios.get('http://localhost:3001/read/'+id)
        .then(res => {
            console.log(res)
            setPhotosensor(res.data[0]);
        })
        .catch(err => console.log(err))
    }, [])
    
    return (
        <div className='d-flex vh-100 bg-primary justify-content-center align-items-center'>
            <div className='w-50 bg-white rounded p-3'>
                <div className='p-2'>
                    <h2>Parking</h2>
                    <h2>{photosensor.id}</h2>
                    <h2>{photosensor.parking_name}</h2>
                    <h2>{photosensor.status}</h2>
                    <Link to="/" className='btn btn-primary me-2'>Back</Link>
                    <Link to={`/edit/${photosensor.id}`} className='btn btn-info'>Edit</Link>
                </div>
            </div>
        </div>
    )
  }
  
  export default Read;